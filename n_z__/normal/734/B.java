import java.util.Scanner;  
public class Main { 
private static Scanner sc;
public static void main(String[] args) {
    Scanner(0);
} 
public static void Scanner(int sum){ 
    sc = new Scanner(System.in); 
    int a = sc.nextInt();
    int b = sc.nextInt();
    int c = sc.nextInt();
    int d = sc.nextInt();
    System.out.println(256*Math.min(a,Math.min(c,d))+32*Math.min(a-Math.min(a,Math.min(c,d)),b)); 
	} 
}