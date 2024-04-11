import java.io.*;
import java.util.*;

public class lazystudent {
  private static InputReader in;
  private static PrintWriter out;
  static class Edge implements Comparable<Edge> {
    public int weight,type,index;
    public Edge(int weight, int type, int index) {
      this.weight = weight;
      this.type = type;
      this.index = index;
    }
    public int compareTo(Edge other) {
      if (weight == other.weight) {return other.type - type;}
      return weight - other.weight;
    }
  }
  
  static class Pair {
    public int a,b;
    public Pair(int a, int b) {
      this.a = a;
      this.b = b;
    }
  }

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);

    int n = in.nextInt(), m = in.nextInt();
    Edge[] e = new Edge[m];
    for (int i = 0; i < m; i++) {
      e[i] = new Edge(in.nextInt(), in.nextInt(),i);
    }
    Arrays.sort(e);
    Pair[] res = new Pair[m];
    Pair[] queue = new Pair[m];
    int front = 0, back = 0;
    int curc = 2;
    for (int i = 0; i < m; i++) {
      if (e[i].type == 1) {
        res[e[i].index] = new Pair(1, curc);
        for (int j = 2; back < m && j < curc; j++) {
          queue[back++] = new Pair(j, curc);
        }
        curc++;
      } else {
        if (front == back) {
          out.println(-1);
          out.close();
          System.exit(0);
        }
        res[e[i].index] = queue[front++];
      }
    }
    
    for (int i = 0; i < m; i++) {
      out.println(res[i].a+" "+res[i].b);
    }
    
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