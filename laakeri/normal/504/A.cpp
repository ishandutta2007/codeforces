#include <iostream>
#include <queue>
#include <vector>
#define F first
#define S second

using namespace std;

int d[100001];
int s[100001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    queue<int> lol;
    for (int i=0;i<n;i++){
        cin>>d[i]>>s[i];
        if (d[i]==1){
            lol.push(i);
        }
    }
    vector<pair<int, int> > v;
    while (!lol.empty()){
        int asd=lol.front();
        lol.pop();
        if (d[asd]==1){
            v.push_back({asd, s[asd]});
            s[s[asd]]^=asd;
            d[s[asd]]--;
            if (d[s[asd]]==1){
                lol.push(s[asd]);
            }
        }
    }
    cout<<v.size()<<'\n';
    for (auto vv:v){
        cout<<vv.F<<" "<<vv.S<<'\n';
    }
}