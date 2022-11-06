#include <iostream>
#include <fstream>
#include <stdio.h>
#include <list>
#include <stack>
#include <deque>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <ext\hash_set>
#include <bitset>
#include <vector>
#include <cmath>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <time.h>
#include <ctime>

using namespace std;

typedef long long ll;

int prost(int o){
    int y=1;
    for (int f=2;f<o;f++)
        y=min(y,o%f);
    return y;
}
int main()
{
    int n,i[1000],k=0,z=2;
    cin>>n;
    while (z<=n){
        if (prost(z)!=0) {
            int s=z;
            while (s<=n){
                i[k]=s;
                k++;
                s*=z;
            }
        }
        z++;
    }
    cout<<k<<endl;
    for (n=0;n<k;n++)
        cout<<i[n]<<' ';
    return 0;
}