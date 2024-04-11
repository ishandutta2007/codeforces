#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct dude{
    string s1,s2;
    int ord;
    bool operator<(const dude&dude2) const{
        return ord<dude2.ord;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<string> ss;
    vector<dude> dudes(n);
    for (int i=0;i<n;i++){
        cin>>dudes[i].s1;
        cin>>dudes[i].s2;
        ss.push_back(dudes[i].s1);
        ss.push_back(dudes[i].s2);
    }
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        dudes[a-1].ord=i;
    }
    sort(dudes.begin(), dudes.end());

    string es="";

    for (int i=0;i<n;i++){
        //cout<<dudes[i].s1<<" "<<dudes[i].s2<<" "<<es<<" "<<dudes[i].ord<<endl;
        if (dudes[i].s1>es&&dudes[i].s2>es){
            if (dudes[i].s1<dudes[i].s2){
                es=dudes[i].s1;
            }
            else{
                es=dudes[i].s2;
            }
        }
        else if (dudes[i].s1>es){
            es=dudes[i].s1;
        }
        else if (dudes[i].s2>es){
            es=dudes[i].s2;
        }
        else{
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
}