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

int main()
{
        ll n,m,k;
        cin>>n>>m>>k;
        int *A=new int [n];
        rep(i,0,n)
                scanf("%d",A+i);
        ll mn=k * (m/((n+1)/2));
        if ((n&1)==0) mn=0;
        for (int i=0;i<n;i+=2)
                mn=min(mn,ll(A[i]));
		cout<<mn<<endl;
        return 0;      
}
/*
3 4 2
6 2 5
*/