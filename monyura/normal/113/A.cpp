#pragma comment(linker,"/STACK:64000000")
#include <cstdio>
#include <memory>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <complex>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <fstream>
#include <functional>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef short int si;
typedef long double ld;
typedef pair<int,int> pii;
#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)

const double PI=acos(-1.0);

template<class T> inline T SQR(T a){return a*a;}

char Word[3][2][20]={{"lios","liala"},
{"etr","etra"},
{"initis","inites"}};

pii petr(char *str)
{
        int n=strlen(str);
        rep(ch,0,3)
                rep(pol,0,2)
                        if (n>=strlen(Word[ch][pol]) && strcmp(str+n-strlen(Word[ch][pol]),Word[ch][pol])==0)
                                return pii(ch,pol);
        return pii(3,2);
}

int main()
{
        //freopen("test.txt","r",stdin);
        bool ok=true;
        char str[100001];
        int Cnt[4]={0};
        int Pol[3]={0};
        int prev=0;
        int tot=0;
        while (!feof(stdin))
        {
                scanf(" %s",str);
                if (feof(stdin)) break;
                pii res=petr(str);
                Cnt[res.first]++;
                Pol[res.second]++;
                if (res.first<prev)
                        ok=false;
                prev=res.first;
                tot++;
        }
        if (tot==0) ok=false;
        if (Cnt[3]!=0) ok=false;
        int cnt=0;
        rep(i,0,3)
                if (Pol[i]>0) cnt++;
        if (cnt!=1) ok=false;
        if (tot!=1 && Cnt[1]!=1) ok=false;
        puts(ok?"YES":"NO");
        return 0;
}