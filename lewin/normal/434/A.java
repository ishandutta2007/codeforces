import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;


public class Main{
  public static void main (String [] args) {
    Scanner in = new Scanner (System.in);
    PrintWriter out = new PrintWriter (System.out, true);
    
    int N = in.nextInt(), M = in.nextInt();
    int[] arr = new int[M];
    for (int i = 0; i < M; i++) {
      arr[i] = in.nextInt();
    }
    ArrayList<Integer>[] invpos = new ArrayList[N + 1];
    for (int i = 0; i <= N; i++)
      invpos[i] = new ArrayList<Integer> ();
    for (int i = 0; i < M; i++) {
      if (i > 0 && arr[i - 1] != arr[i]) invpos[arr[i]].add(arr[i - 1]);
      if (i < M - 1 && arr[i + 1] != arr[i]) invpos[arr[i]].add(arr[i + 1]);
    }
    for (int i = 0; i <= N; i++)
      Collections.sort(invpos[i]);
    long orig = 0;
    for (int i = 1; i < M; i++) 
      orig += Math.abs(arr[i] - arr[i - 1]);
    long min = orig;
    for (int i = 0; i <= N; i++) {
      if (invpos[i].size() == 0) continue;
      int med = invpos[i].get(invpos[i].size() / 2);
      long delta = 0;
      for (int k : invpos[i]) {
        delta -= Math.abs(k - i) - Math.abs(k - med);
      }
      if (delta + orig < min) min = delta + orig;
    }
    
    out.println (min);
    
  }
}