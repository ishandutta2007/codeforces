#include <bits/stdc++.h>

using namespace std;



#define eps 1e-9

#define pb push_back

#define mp make_pair

#define fr first

#define sc second

#define sz(v) ((int)(v).size())

#define all(v) v.begin(),v.end()

#define same(a,b) (fabs((a)-(b))<eps)

#define set(arr,with) memset(arr,with,sizeof(arr))

#define add(target,value,mod) target = (target+(value))%(mod)

#define put_min(target,value) target = min(target,value)

#define put_max(target,value) target = max(target,value)

typedef long long lld;

typedef pair<int,int> pii;

typedef pair<lld,int> pli;

typedef pair<int,lld> pil;

typedef pair<lld,lld> pll;



#define MAXN 100005



int N;

char S[MAXN];



bool is_num(const string &s)

{

    int n = sz(s);

    if (!n || n > 1 && s[0] == '0') return 0;

    for (int i=0;i<n;i++) if (!isdigit(s[i])) return 0;

    return 1;

}



int main()

{

    gets(S); N = strlen(S);

    vector <string> a, b;

    string tmp;

    for (int i=0;i<=N;i++){

        if (i == N || strchr(";,", S[i])){

            if (is_num(tmp)) a.pb(tmp);

            else b.pb(tmp);

            tmp = "";

        }else tmp.pb(S[i]);

    }

    if (sz(a)){

        printf("\"");

        for (int i=0;i<sz(a);i++) printf("%s%s", i ? "," : "", a[i].c_str()); puts("\"");

    }else puts("-");

    if (sz(b)){

        printf("\"");

        for (int i=0;i<sz(b);i++) printf("%s%s", i ? "," : "", b[i].c_str()); puts("\"");

    }else puts("-");

}