#define taskname "a"
#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(v) (int(v.size()))
#define pch putchar
#define gch getchar()
#define FORD(i,a,b) for (int i=(a); i<=(b); i++)
#define FORP(i,a,b) for (int i=(a); i>=(b); i--)
#define REP(i,n) for (int i=0; i<(n); i++)
#define clean(v) memset(v,0,sizeof(v))

#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

template<typename T> T sqr(const T& c) {return c*c;} 

typedef long long ll;
typedef double lf;

int gcd(int a, int b) {
    return b==0?a:gcd(b,a%b);
}

int main() {
    int n;
    scanf("%d",&n);
    int sum = 0;
    //cerr << "?";
    FORD(i,2,n-1) {
        //cerr << i;
        for (int j = n; j>0; sum += j%i, j/=i);
    }
    int lol = gcd(sum,n-2);
    printf("%d/%d",sum/lol,(n-2)/lol);
}