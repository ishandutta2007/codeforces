#include <iostream>
#include <vector>
#include <cstring>
#include <iomanip>
#include <queue>

#define F first
#define S second

using namespace std;

int n,m;

double vs[501];
double es[150000];

int hasn[501];
int hase[150000];

vector<pair<int,int> > g[501];

vector<int> tc;

struct comp{
    bool operator() (pair<int,double> p1, pair<int,double> p2){
        return p1.S<p2.S;
    }
};

double eval (int x){
    double r=0;
    for (auto e:g[x]){
        if (hase[e.S]==0&&hasn[e.F]==1){
            r+=es[e.S];
        }
    }
    return r;
}

int main(){
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>vs[i];
    }
    for (int i=1;i<=m;i++){
        int a,b;
        double c;
        cin>>a>>b>>c;
        es[i]=c;
        g[a].push_back(make_pair(b,i));
        g[b].push_back(make_pair(a,i));
    }
    double bv=0;
    priority_queue<pair<int,double>,vector<pair<int,double> >, comp> take;
    for (int i=1;i<=n;i++){
        //cout <<"alkaa"<<i<<endl;
        memset(hasn,0,sizeof(hasn));
        memset(hase,0,sizeof(hase));

        take=priority_queue<pair<int,double>,vector<pair<int,double> >, comp>();
        double vn=vs[i];
        double ve=0;
        double valn=0;
        hasn[i]=1;
        int f=0;
        for (auto nx:g[i]){
            take.push(make_pair(nx.F,vs[nx.F]/eval(nx.F)));
            //cout <<"push "<<nx.F<<" "<<vs[nx.F]/eval(nx.F)<<endl;
        }
        int bb=0;
        while (!take.empty()){
            if (bb) break;
            auto t=take.top();
            take.pop();
            if (hasn[t.F]==0){
                //cout <<"ok "<<t.F<<endl;
                hasn[t.F]=1;
                double asd=eval(t.F);
                if ((vn+vs[t.F])/(ve+asd)>valn){
                    f++;
                    //cout <<"valitaan"<<t.F<<endl;
                    //cout <<eval(t.F)<<endl;
                    vn+=vs[t.F];
                    ve+=asd;
                    //cout <<vn<<"/"<<ve<<endl;
                    valn=vn/ve;
                    bv=max(bv,valn);
                    //cout <<"valn"<<valn<<endl;

                    //cout<<t.F<<endl;
                    for (auto e:g[t.F]){
                        if (hase[e.S]==0&&hasn[e.F]){
                            hase[e.S]=1;
                        }
                        if (hasn[e.F]==0){
                            take.push(make_pair(e.F,vs[e.F]/eval(e.F)));
                        }
                    }
                }
                else{
                    bv=max(bv,valn);
                    bb=1;
                    break;
                }
            }
        }
        if (f==n){
            break;
        }
        bv=max(bv,valn);
    }
    cout<<setprecision(20)<<bv<<endl;
}