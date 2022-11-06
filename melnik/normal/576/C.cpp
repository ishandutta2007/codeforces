//#include <iostream>
//#include <fstream>
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
//#include <cstdlib>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <time.h>
#include <ctime>

using namespace std;
typedef long long ll;

#define x first
#define y second

//struct triple {
//    int x,y,num;
//};

vector <pair <int,int> > del[1010];

int main()
{
//    freopen ( "input.txt", "r", stdin);
//    freopen ( "output.txt", "w", stdout);
    int n,k,x1,y1;
//    cin>>n;
    scanf ( "%d", &n );
    for (k=1;k<=n;k++){
//        cin>>x1>>y1;
        scanf ( "%d %d", &x1, &y1 );
        del[x1/1000].push_back(make_pair(y1,k));
//        cin>>v[k].x>>v[k].y;
    }
    for (k=0;k<1001;k++){
        sort(del[k].begin(),del[k].end());
        int dl=del[k].size(),l;
        if (k%2==0)
            for (l=0;l<dl;l++)
//                cout<<del[k][l].y<<' ';
                printf ( "%d %c", del[k][l].y, ' ' );
        else
            for (l=dl-1;l>=0;l--)
//                cout<<del[k][l].y<<' ';
                printf ( "%d %c", del[k][l].y, ' ' );

    }


//----------------------------------
//    sort(v,v+n);
//    for (k=0;k<n;k++)
//        cout<<v[k].x<<' '<<v[k].y<<endl;
//    for (k=0;k<n;k++){
//        del[v[k].x/1000]
//
//    }

//    for (k=0;k<1001;k++){
//        if (k%2==0) {
//            r=i[k].begin();
//            while (r!=i[k].end()){
//                cout<<(*r).second<<' ';
//                r++;
//            }
//
//        } else{
//            r=i[k].end();
//            while (r!=i[k].begin()){
//                cout<<(*r).second<<' ';
//                r--;
//            }
//
//        }
//
//    }
    return 0;
}