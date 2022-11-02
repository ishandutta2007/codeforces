#include <iostream>
#include <map>

using namespace std;

string ss[15];

int k;

int isfb(int a){
    for (int i=0;i<k;i++){
        int f=0;
        for (int ii=0;ii<2;ii++){
            if (ss[i][ii]==a+'a') f++;
        }
        if (f) return i+1;
    }
    return 0;
}

map<char, int> lol;

int main(){
    int n;
    string s;
    cin>>s;
    n=s.size();
    cin>>k;
    for (int i=0;i<k;i++){
        cin>>ss[i];
    }
    int isp=0;
    int ta=-1;
    int v=0;
    for (int i=0;i<n;i++){
        if (isfb(s[i]-'a')==ta){
            lol[s[i]]++;
        }
        else{
            if (ta>-1&&lol.size()>1){
                int mi=1000000;
                for (auto asd:lol){
                    mi=min(asd.second, mi);
                }
                v+=mi;
            }
            lol.clear();
            ta=-1;
            if (isfb(s[i]-'a')){
                ta=isfb(s[i]-'a');
                lol[s[i]]++;
            }
        }
    }
    if (ta>-1&&lol.size()>1){
        int mi=1000000;
        for (auto asd:lol){
            mi=min(asd.second, mi);
        }
        v+=mi;
    }
    cout<<v<<endl;
}