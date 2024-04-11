import java.util.Scanner;
import java.util.List;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Comparator;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Collections;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author 
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskD {
    public void solve(int testNumber, Scanner in, PrintWriter out) {
        int n = in.nextInt();
        int[] winner = new int[n];
        int[] numPetyaWins = new int[n + 1];
        for (int i = 0; i < n; ++i) {
            winner[i] = in.nextInt();
            numPetyaWins[i + 1] = numPetyaWins[i];
            if (winner[i] == 1) {
                ++numPetyaWins[i + 1];
            }
        }
        int lastWin = 0;
        List<int[]> answer = new ArrayList<int[]>();
        outer: for (int setUnit = 1; setUnit <= n; ++setUnit) {
            int win1 = 0, win2 = 0;
            for (int i = 0; i < n; ) {
                int left = i, right = n - 1;
                while (left < right) {
                    int mid = ((left + right) >> 1) + 1;
                    if (numPetyaWins[mid] - numPetyaWins[i] >= setUnit
                            || mid - i - (numPetyaWins[mid] - numPetyaWins[i]) >= setUnit) {
                        right = mid - 1;
                    } else {
                        left = mid;
                    }
                }
                if (numPetyaWins[left + 1] - numPetyaWins[i] == setUnit) {
                    ++win1;
                    lastWin = 1;
                } else if (left + 1 - i - (numPetyaWins[left + 1] - numPetyaWins[i]) == setUnit) {
                    ++win2;
                    lastWin = 2;
                } else continue outer;

                i = left + 1;
            }
            if (win1 > win2 && lastWin == 1 || win1 < win2 && lastWin == 2) {
                answer.add(new int[]{Math.max(win1, win2), setUnit});
            }
        }
        Collections.sort(answer, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                if (o1[0] != o2[0]) {
                    return o1[0] - o2[0];
                }
                return o1[1] - o2[1];
            }
        });
        out.println(answer.size());
        for (int[] answerItem : answer) {
            out.println(answerItem[0] + " " + answerItem[1]);
        }
    }
}