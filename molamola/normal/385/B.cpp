#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<ctype.h>
using namespace std;

#define X first
#define Y second
typedef long long ll;
typedef pair<int,int> Pi;

char ch[5050];
vector <int> mat;

int main()
{
    scanf("%s",ch+1);
    int len = strlen(ch+1);
    if(len<=3){printf("0");return 0;}
    for(int i=1;i<=len-3;i++){
        if(ch[i]=='b'&&ch[i+1]=='e'&&ch[i+2]=='a'&&ch[i+3]=='r')mat.push_back(i);
    }
    int ans = 0;
    int now = 0;
    for(int i=1;i<=len-3;i++){
        if(now == mat.size())break;
        int t = mat[now];
        if(i>t)now++;
        if(now == mat.size())break;
        ans += (len - mat[now] - 2);
    }
    printf("%d",ans);
    return 0;
}