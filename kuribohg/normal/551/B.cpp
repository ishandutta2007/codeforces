#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int INF=1000000000;
char a[1000010],b[1000010],c[1000010];
int cnta[26],cntb[26],cntc[26],cnt[26],lena,lenb,lenc,ansb,ansc,ans;
void print(char str[])
{
    int len=strlen(str);
    for(int i=0;i<len;i++) putchar(str[i]),cnta[str[i]-'a']--;
}
int main()
{
    scanf("%s%s%s",a,b,c);
    lena=strlen(a),lenb=strlen(b),lenc=strlen(c);
    for(int i=0;i<lena;i++) cnta[a[i]-'a']++;
    for(int i=0;i<lenb;i++) cntb[b[i]-'a']++;
    for(int i=0;i<lenc;i++) cntc[c[i]-'a']++;
    for(int i=0;i<=lena;i++)
    {
        bool ok=true;
        for(int j=0;j<26;j++) cnt[j]=cnta[j]-cntb[j]*i;
        for(int j=0;j<26;j++) if(cnt[j]<0) ok=false;
        if(!ok) break;
        int p=INF;
        for(int j=0;j<26;j++)
        {
            if(cntc[j]==0) continue;
            p=min(p,cnt[j]/cntc[j]);
        }
        if(ans<i+p) ans=i+p,ansb=i,ansc=p;
    }
    for(int i=1;i<=ansb;i++) print(b);
    for(int i=1;i<=ansc;i++) print(c);
    for(int i=0;i<26;i++)
        for(int j=1;j<=cnta[i];j++)
            putchar(i+'a');
    puts("");
    return 0;
}