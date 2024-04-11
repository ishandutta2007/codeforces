#include <stdio.h>
#include <algorithm>
using namespace std;

#define MAXN 100005

int N,K,M=26,cnt[26],p[26];
char buf[MAXN];
bool chk[26];

bool cmp(int a,int b){ return cnt[a]<cnt[b]; }

int main()
{
    int i,k=0;
    scanf("%s%d",buf,&K);
    for (i=0;buf[i];i++) cnt[buf[i]-'a']++;
    for (i=0;i<26;i++) p[i] = i;
    sort(p,p+26,cmp);
    for (i=0;i<26;i++){
        k += cnt[p[i]];
        if (k > K) break;
        chk[p[i]] = 1; M--;
    }
    printf("%d\n",M);
    for (i=0;buf[i];i++) if (!chk[buf[i]-'a']) printf("%c",buf[i]);
}