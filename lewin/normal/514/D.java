import java.io.*;
import java.util.*;

public class r2d2droid {
  private static InputReader in;
  private static PrintWriter out;
  
  public static int MAXN = 100010;
  static class MaxStack {
    public int[] stack;
    public int[] items;
    public int idx;
    public MaxStack() {
      stack = new int[MAXN];
      items = new int[MAXN];
      idx = 0;
    }
    
    public void push(int item) {
      items[idx] = item;
      if (idx == 0) {
        stack[idx++] = item;
      } else {
        stack[idx] = Math.max(stack[idx-1], item);
        idx++;
      }
    }
    
    public int pop() {
      return items[--idx];
    }
    
    public int query() {
      if (idx == 0) return -Integer.MAX_VALUE;
      return stack[idx-1];
    }
    
    public boolean empty() {
      return idx == 0;
    }
  }
  
  static class MaxQueue {
    public MaxStack f,b;
    public MaxQueue() {
      f = new MaxStack();
      b = new MaxStack();
    }
    
    public void push(int item) {
      f.push(item);
    }
    
    public void pop() {
      if (b.empty()) {
        while (!f.empty()) b.push(f.pop());
      }
      b.pop();
    }
    
    public void popFront() {
      f.pop();
    }
    
    public int query() {
      return Math.max(f.query(), b.query());
    }
  }

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);
    int N = in.nextInt();
    int M = in.nextInt();
    int K = in.nextInt();
    int[][] arr = new int[N][M];
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) 
        arr[i][j] = in.nextInt();
    }
    
    long[] ret = new long[M];
    int maxSeen = 0;
    int back = 0;
    MaxQueue[] mqs = new MaxQueue[M];
    for (int i = 0; i < M; i++) mqs[i] = new MaxQueue();
    for (int front = 0; front < N; front++) {
      if (back < front) back = front;
      while (back < N) {
        for (int j = 0; j < M; j++) mqs[j].push(arr[back][j]);
        int cost = 0;
        for (int j = 0; j < M; j++) cost += mqs[j].query();
        if (cost > K) {
          for (int j = 0; j < M; j++) mqs[j].popFront();
          break;
        }
        back++;
      }
      if (back - front > maxSeen) {
        maxSeen = back - front;
        for (int j = 0; j < M; j++) ret[j] = mqs[j].query();
      }
      if (back > front) for (int j = 0; j < M; j++) mqs[j].pop();
    }
    
    out.print(ret[0]);
    for (int i = 1; i < M; i++) out.print(" "+ret[i]);
    out.println();
    out.close();
    System.exit(0);
  }

  static class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
      reader = new BufferedReader(new InputStreamReader(stream), 32768);
      tokenizer = null;
    }

    public String next() {
      while (tokenizer == null || !tokenizer.hasMoreTokens()) {
        try {
          tokenizer = new StringTokenizer(reader.readLine());
        } catch (IOException e) {
          throw new RuntimeException(e);
        }
      }
      return tokenizer.nextToken();
    }

    public int nextInt() {
      return Integer.parseInt(next());
    }
  }


}