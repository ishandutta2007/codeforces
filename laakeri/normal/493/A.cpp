#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<pair<char, int>, int> asd;

int main(){
    string ht;
    string et;
    cin>>ht>>et;
    vector<pair<string, pair<int, int> > > v;
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        int t;
        cin>>t;
        char a;
        cin>>a;
        int m;
        cin>>m;
        char c;
        cin>>c;
        pair<char, int> p={a, m};
        if (c=='r'){
            if (asd[p]<2){
                if (a=='h'){
                    v.push_back(make_pair(ht, make_pair(t, m)));
                }
                else{
                    v.push_back(make_pair(et, make_pair(t, m)));
                }
                asd[p]=2;
            }
        }
        else{
            asd[p]++;
            if (asd[p]==2){
                if (a=='h'){
                    v.push_back(make_pair(ht, make_pair(t, m)));
                }
                else{
                    v.push_back(make_pair(et, make_pair(t, m)));
                }
            }
        }
    }
    for (auto lol:v){
        cout<<lol.first<<" "<<lol.second.second<<" "<<lol.second.first<<endl;
    }
}