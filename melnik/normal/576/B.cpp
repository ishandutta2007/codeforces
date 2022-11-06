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

int main()
{
    int n,i[100000][2],k,z[100000][2],first,tek,dl=0,sc=0,mi=2e9,f=0;
    vector <int> v;
    vector <vector <int> >v2;
    cin>>n;
    v.resize(n+1);
    v2.resize(n+1);
    for (k=0;k<n;k++){
        cin>>i[k][0];
        v[i[k][0]]=k;
        i[k][1]=0;
    }
    for (k=0;k<n;k++){
        if (i[k][1]==0){
            i[k][1]=1;
            v2[sc].push_back(i[k][0]);
            tek=i[k][0]-1;
            dl=1;
            while (tek!=k){
                i[tek][1]=1;
                v2[sc].push_back(i[tek][0]);
                tek=i[tek][0]-1;
                dl++;
            }
            sc++;
        }
    }
    for (k=0;k<sc;k++){
        mi=min(mi,(int)v2[k].size());
        f=max(f,(int)(v2[k].size()%2));
    }
    if (mi>2||(mi==2&&f>0)) cout<<"NO"<<endl; else{
        cout<<"YES"<<endl;
        if (mi==1) {
            for (k=0;k<sc;k++)
                if (v2[k].size()==1) break;
            mi=v2[k][0];
            for (f=1;f<=n;f++)
                if (f!=mi) cout<<f<<' '<<mi<<endl;

        } else
        {
            for (k=0;k<sc;k++)
                if (v2[k].size()==2) break;
            dl=k;
            int z1=v2[k][0],z2=v2[k][1];
            cout<<z1<<' '<<z2<<endl;
            for (k=0;k<sc;k++){
                if (k!=dl){
                    int l=v2[k].size();
                    for (int y=0;y<l;y+=2)
                    {
                        cout<<z1<<' '<<v2[k][y]<<endl;
                        cout<<z2<<' '<<v2[k][y+1]<<endl;
                    }
                }

            }
        }

    }


//    for (k=0;k<n&&f==0;k++){
//        if (i[k][1]==0){
//            i[k][1]=1;
//            prev=k+1;
//            tek=i[k][0];
//            if (i[tek-1][0]!=prev||i[k][0]-1==k) f=1; else
//            {
//                z[sc][0]=i[k][0];
//                i[tek-1][1]=1;
//                z[sc][1]=i[tek-1][0];
//                sc++;
//            }
//        }
//    }
//    if (f==1) cout<<"NO"<<endl;
//    else
//    {
//        cout<<"YES"<<endl;
//        for (n=0;n<sc;n++)
//        cout<<z[n][0]<<' '<<z[n][1]<<endl;
//    }

    return 0;
}