#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;

int N;
char A[99];
string ans="";

bool chk(string str)
{
    int n=str.length(),i;
    for (i=0;i<n;i++) if (str[i] != str[n-i-1]) return 0;
    return 1;
}

void dfs(int n,string str)
{
    if (n > N){
        if (chk(str)){
            if (ans < str)
                ans = str;
        }
        return;
    }
    dfs(n+1,str);
    str.push_back(A[n]);
    dfs(n+1,str);
}

int main()
{
    scanf("%s",A+1);
    N = strlen(A+1);
    dfs(1,"");
    printf("%s",ans.c_str());
}