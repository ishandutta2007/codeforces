/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxN= 10000 + 5;

bool flag[5];
int n,m,k;
int a[maxN];

int main(){

    cin >> n >> m >> k;

    for (int i=1;i<=n;i++) cin >> a[i];

  //  if (n==1) {cout << a[1] << endl; return 0;}

    if (n%2==0) {cout << 0 << endl; return 0;}

    int mini=1;

    for (int i=3;i<=n;i+=2) if (a[i] < a[mini]) mini=i;

    int per= (ll)m*2/(n+1);

    cout << min ((ll)per*k , (ll)a[mini]) << endl;

    return 0;
}