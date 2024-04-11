#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <memory.h>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;
typedef long long li;
typedef long double ld;
#define mp make_pair
#define pb push_back
typedef pair <int, int> pi;
typedef vector <int> vi;
void solve ();
int main ()
{
#ifdef _DEBUG
        freopen ("in.txt", "r", stdin);
        //freopen ("out.txt", "w", stdout);
#endif
        solve ();
}
//#define int li
int n, k, a[100500], b[100500], t;
int search ( int val )
{
        int l=0, r=t;
        //cout<<l<<" "<<r<<endl;
        while (l+1<r)
        {
                int med=(l+r)/2;
                //cout<<"shit";
                //cout<<val<<" "<<med<<"!"<<endl;
                if ( b[med]>val )
                        r=med;
                else 
                        l=med;
        }
        //cout<<"val"<<" "<<val<<endl;
        return l;
}
int curnum[100500];
set <int> have;
void solve ()
{
        cin>>n>>k;
        for (int i=0; i<n; i++)
        {
                cin>>a[i];
                b[i]=a[i];
        }
        sort (b, b+n);
        t=(unique (b, b+n)-b);
        //cout<<"t="<<t<<endl;
        for (int i=0; i<k; i++)
        {
                int mesto=search(a[i]);
                if ( curnum[mesto]==0 )
                        have.insert(a[i]);
                else 
                        have.erase (a[i]);
                curnum[mesto]++;
                //cout<<a[i]<<" "<<mesto<<endl;
        }
	       if (have.size()==0)
                {
                        printf ("Nothing\n");
                }
else 
        cout<<*have.rbegin()<<endl;
        for (int i=0; i+k<n; i++)
        {
                if ( a[i]==a[i+k] )
                {
                        if (have.size()==0)
                {
                        printf ("Nothing\n");
                        continue;
                }
                        cout<<*have.rbegin()<<endl;
                        continue;
                }
                curnum[search(a[i])]--;
                curnum[search(a[i+k])]++;
                //cout<<curnum[search(a[i])]<<" "<<curnum[search(a[i+k])]<<endl;
                have.erase(a[i]);
                if ( curnum[search(a[i+k])]==1 )
                        have.insert(a[i+k]);
                else
                        have.erase (a[i+k]);
                if ( curnum[search(a[i])]==1 )
                        have.insert (a[i]);
                if (have.size()==0)
                {
                        printf ("Nothing\n");
                        continue;
                }
                cout<<*have.rbegin()<<endl;
        }
}