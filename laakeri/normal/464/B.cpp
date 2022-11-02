#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll vs[8][3];

vector<vector<ll> > lol;

ll p2(ll a){
    return a*a;
}

int f=0;

void rec(int i, vector<ll> &nn){
    if (f) return;
    if (i>0) lol.push_back(nn);
    if (i<8){
        vector<ll> n(3);
        n[0]=vs[i][0];
        n[1]=vs[i][1];
        n[2]=vs[i][2];
        rec(i+1, n);
        swap(n[1], n[2]);
        rec(i+1, n);
        swap(n[0], n[1]);
        rec(i+1, n);
        swap(n[1], n[2]);
        rec(i+1, n);
        swap(n[0], n[1]);
        rec(i+1, n);
        swap(n[1], n[2]);
        rec(i+1, n);
    }
    if (i==8){
        for (int ii=0;ii<8;ii++){
            vector<ll> ds;
            vector<int> dss;
            for (int jj=0;jj<8;jj++){
                if (ii!=jj){
                    ll d=p2(lol[jj][0]-lol[ii][0])+p2(lol[jj][1]-lol[ii][1])+p2(lol[jj][2]-lol[ii][2]);
                    if (d==0ll){
                        lol.pop_back();
                        return;
                    }
                    int ff=0;
                    for (int iii=0;iii<ds.size();iii++){
                        if (d==ds[iii]){
                            ff=1;
                            dss[iii]++;
                        }
                    }
                    if (!ff){
                        if (ds.size()==3){
                            lol.pop_back();
                            return;
                        }
                        else{
                            ds.push_back(d);
                            dss.push_back(1);
                        }
                    }
                }
            }
            if (ds.size()!=3){
                lol.pop_back();
                return;
            }
            if (dss[0]==1){
                swap(ds[0], ds[2]);
                swap(dss[0], dss[2]);
            }
            if (dss[1]==1){
                swap(ds[1], ds[2]);
                swap(dss[1], dss[2]);
            }
            if (dss[0]!=3||dss[1]!=3||dss[2]!=1){
                lol.pop_back();
                return;
            }
            if (ds[0]>ds[1]){
                swap(ds[0], ds[1]);
            }
            if (ds[1]!=2*ds[0]||ds[2]!=3*ds[0]){
                lol.pop_back();
                return;
            }
        }
        f=1;
        cout<<"YES"<<endl;
        for (int ii=0;ii<8;ii++){
            for (int iii=0;iii<3;iii++){
                cout<<lol[ii][iii]<<" ";
            }
            cout<<endl;
        }
    }
    if (i>0) lol.pop_back();
}

int main(){
    for (int i=0;i<8;i++){
        for (int ii=0;ii<3;ii++){
            cin>>vs[i][ii];
        }
    }
    vector<ll> asd;
    rec(0, asd);
    if (!f){
        cout<<"NO"<<endl;
    }
}