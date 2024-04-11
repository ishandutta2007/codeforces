import java.util.Scanner;
import java.util.Arrays;
public class learn {
    public static void main(String[] args)
    {
        Scanner s=new Scanner(System.in);
        int arr[]=new int[4];
        for (int i=0;i<4;i++) {
            arr[i]=s.nextInt();
        }
        Arrays.sort(arr);
        if (arr[0]+arr[1]>arr[2] || arr[1]+arr[2]>arr[3])
        System.out.println("TRIANGLE");
        else if (arr[0]+arr[1]==arr[2] || arr[1]+arr[2]==arr[3])
        System.out.println("SEGMENT");
        else
        System.out.println("IMPOSSIBLE");
    }
}