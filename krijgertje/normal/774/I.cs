using System;
class Program
{
    static void Main()
    {
        int n = Convert.ToInt32(Console.ReadLine());
        string[] p = new string[n];
        for(int i=0;i<n;++i) p[i]=Console.ReadLine();
        string s=Console.ReadLine();
        int len=s.Length;
        int[] dp=new int[len+1];
        for(int i=0;i<=len;++i) dp[i]=Int32.MaxValue;
        dp[0]=0;
        for(int at=0;at<len;++at) if(dp[at]!=Int32.MaxValue) {
            for(int i=0;i<n;++i) {
                int to=at;
                for(int j=0;j<p[i].Length;++j) {
                    if(to<len&&s[to]==p[i][j]) ++to;
                }
                if(dp[at]+1<dp[to]) dp[to]=dp[at]+1;
            }
        }
        Console.WriteLine(dp[len]==Int32.MaxValue?-1:dp[len]);
    }

}