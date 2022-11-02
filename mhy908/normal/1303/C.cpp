#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define sortvec(x) sort(all(x))
#define compress(x) x.erase(unique(all(x)), x.end())
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef pair<int, LL> pil;
typedef pair<LL, int> pli;
const LL llinf=1987654321987654321;
const int inf=2000000000;
int t;
char str[210];
vector<int> s[30];
bool ch[30];
int main(){
    scanf("%d", &t);
    for(int u=1; u<=t; u++){
        memset(ch, 0, sizeof ch);
        memset(str, 0, sizeof str);
        scanf("%s", str+1);
        int len=strlen(str+1);
        if(len==1){
            puts("YES");
            printf("%c", str[1]);
            for(int i=1; i<=26; i++){
                if(str[1]-'a'+1==i)continue;
                printf("%c", i+'a'-1);
            }
            puts("");
            continue;
        }
        for(int i=1; i<=26; i++)s[i].clear();
        for(int i=2; i<=len; i++){
            ch[str[i]-'a'+1]=true;
            ch[str[i-1]-'a'+1]=true;
            s[str[i]-'a'+1].pb(str[i-1]-'a'+1);
            s[str[i-1]-'a'+1].pb(str[i]-'a'+1);
        }
        bool flag=false;
        int num=0;
        int st=0;
        for(int i=1; i<=26; i++){
            sortvec(s[i]);
            compress(s[i]);
            if(s[i].size()>=3)flag=true;
            if(s[i].size()==1){
                st=i;
                num++;
            }
        }
        if(flag||num!=2){
            puts("NO");
            continue;
        }
        puts("YES");
        int now=st, prv=st;
        printf("%c", now+'a'-1);
        now=s[now][0];
        while(1){
            printf("%c", now+'a'-1);
            if(s[now].size()==1)break;
            if(s[now][0]==prv){
                prv=now;
                now=s[now][1];
            }
            else{
                prv=now;
                now=s[now][0];
            }
        }
        for(int i=1; i<=26; i++){
            if(!ch[i])printf("%c", i+'a'-1);
        }
        puts("");
    }
}