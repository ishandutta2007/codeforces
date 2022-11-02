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



#define MAXN 200005



int N;

int cnt[26];

char S[MAXN], X[MAXN];



int main()

{

    gets(S); N = strlen(S);

    for (int i=0;i<N;i++) cnt[S[i]-'a']++;

    vector <int> arr;

    for (int i=0;i<26;i++) if (cnt[i]&1){

        arr.pb(i);

    }

    for (int i=0;i<sz(arr)/2;i++){

        cnt[arr[i]]++;

        cnt[arr[sz(arr)-i-1]]--;

    }

    int p = 1, q = N;

    for (int i=0;i<26;i++){

        while (cnt[i] > 1){

            X[p++] = i+'a';

            X[q--] = i+'a';

            cnt[i] -= 2;

        }

    }

    if (p == q){

        for (int i=0;i<26;i++) if (cnt[i]) X[p] = i+'a';

    }

    puts(X+1);

}