import java.io.*;
import java.util.*;

public class littleartemtimetravel {
  private static InputReader in;
  private static PrintWriter out;

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);

    HashMap<Integer, Treap> plus = new HashMap<>();
    HashMap<Integer, Treap> minus = new HashMap<>();
    
    int n = in.nextInt();
    while(n-->0) {
      int type = in.nextInt();
      if (type == 1) {
        int time = in.nextInt(), which = in.nextInt();
        Treap t = plus.get(which);
        t = insert(t, time);
        plus.put(which, t);
      } else if (type == 2) {
        int time = in.nextInt(), which = in.nextInt();
        Treap t = minus.get(which);
        t = insert(t, time);
        minus.put(which, t);
      } else {
        int time = in.nextInt(), which = in.nextInt();
        Treap t1 = plus.get(which);
        Treap t2 = minus.get(which);
        out.println(countBelow(t1, time)-countBelow(t2, time));
      }
    }
    
    out.close();
    System.exit(0);
  }
  static Random random = new Random();

  static class Treap {
    int key;
    long prio;
    Treap left;
    Treap right;
    int count;

    Treap(int key) {
      this.key = key;
      prio = random.nextLong();
      count = 1;
    }

    void update() {
      count = 1 + getCount(left) + getCount(right);
    }
  }

  static int getCount(Treap root) {
    return root == null ? 0 : root.count;
  }

  static class TreapPair {
    Treap left;
    Treap right;

    TreapPair(Treap left, Treap right) {
      this.left = left;
      this.right = right;
    }
  }

  static TreapPair split(Treap root, int minRight) {
    if (root == null)
      return new TreapPair(null, null);
    if (root.key >= minRight) {
      TreapPair leftSplit = split(root.left, minRight);
      root.left = leftSplit.right;
      root.update();
      leftSplit.right = root;
      return leftSplit;
    } else {
      TreapPair rightSplit = split(root.right, minRight);
      root.right = rightSplit.left;
      root.update();
      rightSplit.left = root;
      return rightSplit;
    }
  }

  static Treap merge(Treap left, Treap right) {
    if (left == null)
      return right;
    if (right == null)
      return left;
    if (left.prio > right.prio) {
      left.right = merge(left.right, right);
      left.update();
      return left;
    } else {
      right.left = merge(left, right.left);
      right.update();
      return right;
    }
  }

  static Treap insert(Treap root, int x) {
    if (root == null) return new Treap(x);
    TreapPair t = split(root, x);
    return merge(merge(t.left, new Treap(x)), t.right);
  }
  
  static int countBelow(Treap root, int k) {
    if (root == null) return 0;
    if (k < root.key) return countBelow(root.left, k);
    else {
      return 1 + getCount(root.left) + countBelow(root.right, k);
    }
  }
  static void print(Treap root) {
    if (root == null)
      return;
    print(root.left);
    System.out.println(root.key);
    print(root.right);
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