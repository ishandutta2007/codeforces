#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
#include<string>
#include<set>
#include<ctype.h>
using namespace std;

#define X first
#define Y second
typedef long long ll;
typedef pair<int,int> Pi;

string inp[100010];
string a;
char ch[100010];

int main()
{
    int n;
    scanf("%d\n",&n);
    int i;
    ch[0]='<',ch[1]='3',ch[2]=0;
    a+=ch;
    for(i=1;i<=n;i++){
        gets(ch);
        inp[i]=ch;
        a+=inp[i];
        ch[0]='<',ch[1]='3',ch[2]=0;
        a+=ch;
    }
    gets(ch);
    int p=0;
    for(i=0;ch[i];i++){
        if(a[p]==ch[i])p++;
        if(p==a.length()){printf("yes");return 0;}
    }
    printf("no");
    return 0;
}