#include <iostream>
#include <vector>
#include <set>
#define F first
#define S second

using namespace std;

int a[301];
int c[301];

int dp[1<<20];

int main(){
    vector<int> ps;
    int mv=1e9;
    for (int i=2;i*i<=mv;i++){
        int f=0;
        for (int p:ps){
            if (i%p==0){
                f=1;
                break;
            }
        }
        if (!f){
            ps.push_back(i);
        }
    }
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    for (int i=0;i<n;i++){
        cin>>c[i];
    }
    for (int i=0;i<n;i++){
        //cout<<"i "<<i<<endl;
        int v=c[i];
        set<int> ts;
        int xx=a[i];
        for (int ii=0;ii<ps.size();ii++){
            while (xx%ps[ii]==0){
                ts.insert(ps[ii]);
                xx/=ps[ii];
            }
            if (ps[ii]*ps[ii]>xx) break;
        }
        if (xx>1) ts.insert(xx);
        vector<int> tss;
        for (int x:ts){
            tss.push_back(x);
        }
        int bml=tss.size();
        vector<pair<int, int> > bms;
        for (int ii=0;ii<n;ii++){
            if (i!=ii){
                int bm=0;
                for (int iii=0;iii<bml;iii++){
                    if (a[ii]%tss[iii]!=0){
                        //cout<<a[ii]<<" x "<<tss[iii]<<endl;
                        bm|=(1<<iii);
                    }
                }
                //cout<<bm<<endl;
                bms.push_back({bm, c[ii]});
            }
        }
        for (int ii=0;ii<(1<<bml);ii++){
            dp[ii]=-1;
        }
        //cout<<bml<<" "<<(1<<bml)-1<<endl;
        dp[0]=v;
        //cout<<bml<<endl;
        for (int ii=0;ii<(1<<bml);ii++){
            if (dp[ii]!=-1){
                //cout<<ii<<" "<<dp[ii]<<endl;
                for (int iii=0;iii<bms.size();iii++){
                    int ne=ii|bms[iii].F;
                    if (dp[ne]==-1||dp[ne]>dp[ii]+bms[iii].S){
                        dp[ne]=dp[ii]+bms[iii].S;
                    }
                }
            }
        }
        //cout<<dp[(1<<bml)-1]<<endl;
        if (dp[(1<<bml)-1]!=-1){
            mv=min(dp[(1<<bml)-1], mv);
        }
    }
    if (mv==1e9){
        cout<<-1<<endl;
        return 0;
    }
    cout<<mv<<endl;
}