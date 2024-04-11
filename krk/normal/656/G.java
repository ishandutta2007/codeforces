import java.io.*;
import java.util.Arrays;

public class Main {

public static void main(String[] args) throws Exception {
    BufferedReader fin = new BufferedReader(new InputStreamReader(System.in));
    int n, m, th;
    String s[] = fin.readLine().split(" ");
    n = Integer.parseInt(s[0]); m = Integer.parseInt(s[1]); th = Integer.parseInt(s[2]);
    int arr[] = new int[m];
    Arrays.fill(arr, 0);
    for (int i = 0; i < n; i++) {
        String my = fin.readLine();
        for (int j = 0; j < m; j++)
            if (my.charAt(j) == 'Y') arr[j]++;
    }
    int kitten = 0;
    for (int i = 0; i < m; i++)
        if (arr[i] >= th) kitten++;
    System.out.println(kitten);
}
}