#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

int a[5001];

map<int, pair<int, int> > lol1;
map<int, pair<int, int> > lol2;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    for (int i=0;i<n;i++){
        cin>>a[i];
        for (int ii=1;ii<=k;ii++){
            if (lol1[a[i]*ii].F==0||lol1[a[i]*ii].F>ii){
                lol2[a[i]*ii]=lol1[a[i]*ii];
                lol1[a[i]*ii]={ii, i};
            }
            else if(lol2[a[i]*ii].F==0||lol2[a[i]*ii].F>ii){
                lol2[a[i]*ii]={ii, i};
            }
        }
    }
    int q;
    cin>>q;
    for (int i=0;i<q;i++){
        int x;
        cin>>x;
        int mi=50;
        for (int ii=0;ii<n;ii++){
            for (int iii=1;iii<=k;iii++){
                int nee=x-a[ii]*iii;
                if (nee==0) mi=min(mi, iii);
                else if(nee>0){
                    //cout<<ii<<" "<<iii<<" "<<nee<<endl;
                    if (lol1[nee].S!=ii){
                        if (lol1[nee].F>0){
                            mi=min(mi, iii+lol1[nee].F);
                        }
                    }
                    else{
                        if (lol2[nee].F>0){
                            mi=min(mi, iii+lol2[nee].F);
                        }
                    }
                }
            }
        }
        if (mi<=k){
            cout<<mi<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
}