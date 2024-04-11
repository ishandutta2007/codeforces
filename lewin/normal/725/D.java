import java.io.*;
import java.util.*;

public class contestbaloons {
  private static InputReader in;
  private static PrintWriter out;
  
  static class Team {
    public long t,w;
    public long need;
    public Team(long t, long w) {
      this.t = t;
      this.w = w;
      need = w-t+1;
    }
  }

  public static void main(String[] args) throws IOException {
    in = new InputReader(System.in);
    out = new PrintWriter(System.out, true);

    int n = in.nextInt();
    long cbal = Long.parseLong(in.next()); in.next();
    Team[] teams = new Team[n-1];
    for (int i = 0; i < n-1; i++) {
      teams[i] = new Team(Long.parseLong(in.next()), Long.parseLong(in.next()));
    }
    Arrays.parallelSort(teams, new Comparator<Team>() {
      public int compare(Team a, Team b) {
        return Long.compare(b.t, a.t);
      }
    });
    int cp = 0;
    PriorityQueue<Team> pq = new PriorityQueue<>(new Comparator<Team>() {
      public int compare(Team a, Team b) {
        return Long.compare(a.need, b.need);
      }
    });
    for (int i = 0; i < n-1; i++) {
      if (teams[i].t > cbal) {
        cp++;
        pq.add(teams[i]);
      } else {
        break;
      }
    }
    
    int ret = cp;
    int fptr = cp;
    while (pq.size() > 0) {
      Team give = pq.poll();
      if (cbal < give.need) {
        break;
      }
      cbal -= give.need;
      cp--;
      while (fptr < n-1 && teams[fptr].t > cbal) {
        pq.add(teams[fptr]);
        cp++;
        fptr++;
      }
      ret = Math.min(ret, cp);
    }
    out.println(ret+1);
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