import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class A {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		int h = sc.nextInt();
		int[] vals = new int[h + 1];
		int total = 0;
		for (int i = 0; i < vals.length; i++) {
			total += vals[i] = sc.nextInt();
		}
		int[] parent = new int[total];
		int idx = 0, lastPar = -1, dindx = -1, dval = -1;
		boolean amb = false;
		for (int i = 0; i < vals.length; i++) {
			if (i > 0 && vals[i] > 1 && vals[i-1] > 1 && !amb) {
				amb = true;
				dindx = idx + 1;
				dval = lastPar + 2;
			}
			int nextPar = idx;
			for (int j = 0; j < vals[i]; j++) {
				parent[idx++] = lastPar+1;
			}
			lastPar = nextPar;
		}
		if (amb) {
			System.out.println("ambiguous");
			for (int i = 0; i < parent.length; i++) {
				System.out.print(parent[i] + " ");
			}
			System.out.println();
			for (int i = 0; i < parent.length; i++) {
				System.out.print((i == dindx ? dval : parent[i]) + " ");
			}
			System.out.println();
		} else {
			System.out.println("perfect");
		}
	}
}