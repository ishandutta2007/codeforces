#include <bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define llinf 8987654321987654321
#define inf 1987654321
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

int n;
char str1[200010], str2[200010];
int anum, bnum;
int num, ans;
int print[1000010][3], re;
int arr1[200010], re1, arr2[200010], re2;

int main()
{
    scanf("%d", &n);
    scanf("%s %s", str1+1, str2+1);
    for(int i=1; i<=n; i++){
        if(str1[i]=='a')anum++;
        else bnum++;
        if(str2[i]=='a')anum++;
        else bnum++;
    }
    if(anum%2!=0||bnum%2!=0){
        printf("-1");
        return 0;
    }
    for(int i=1; i<=n; i++){
        if(str1[i]=='a'&&str2[i]=='b')arr1[++re1]=i;
        if(str1[i]=='b'&&str2[i]=='a')arr2[++re2]=i;
    }
    for(int i=1; i<=re1/2; i++){
        ans++;
        re++;
        print[re][1]=arr1[i*2-1];
        print[re][2]=arr1[i*2];
    }
    for(int i=1; i<=re2/2; i++){
        ans++;
        re++;
        print[re][1]=arr2[i*2-1];
        print[re][2]=arr2[i*2];
    }
    if(re1%2){
        ans+=2;
        re++;
        print[re][1]=arr1[re1];
        print[re][2]=arr1[re1];
        re++;
        print[re][1]=arr1[re1];
        print[re][2]=arr2[re2];
    }
    printf("%d\n", ans);
    for(int i=1; i<=re; i++){
        printf("%d %d\n", print[i][1], print[i][2]);
    }
}