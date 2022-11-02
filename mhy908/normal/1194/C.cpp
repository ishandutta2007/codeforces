#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int w;
char s[110], t[110], p[110];
int main()
{
    scanf("%d", &w);
    for(int u=1; u<=w; u++){
        for(int i=0; i<=102; i++){
            s[i]=0;
            t[i]=0;
            p[i]=0;
        }
        scanf("%s %s %s", s, t, p);
        int slen=strlen(s);
        int tlen=strlen(t);
        int plen=strlen(p);
        int pv=0;
        bool nope;
        for(int i=0; i<slen; i++){
            while(pv<=105){
                if(t[pv]==s[i]){
                    pv++;
                    break;
                }
                pv++;
            }
        }
        if(pv>103){
            printf("NO\n");
            continue;
        }
        pv=0;
        for(int i=0; i<tlen; i++){
            nope=true;
            if(t[i]==s[pv])pv++;
            else{
                for(int j=0; j<plen; j++){
                    if(t[i]==p[j]){
                        p[j]=0;
                        nope=false;
                        break;
                    }
                }
                if(nope){
                    printf("NO\n");
                    break;
                }
            }
            if(i==tlen-1){
                printf("YES\n");
                break;
            }
        }
    }
}