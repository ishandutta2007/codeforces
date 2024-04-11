#include<bits/stdc++.h>
using namespace std;
int gc(int a, int b){
    if(a==0||b==0){
        return a+b;
    }
    return gc(b%a,a);
}
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int ans[n];
    vector<pair<int, int> > li;
    for(int z=0; z<n; z++){
        string s;
        cin >> s;
        int plus;
        int close;
        int divi;
        
        for(int i = 0; i<s.length(); i++){
            if(s[i]=='+'){
                plus = i;
            }
            else if(s[i]==')'){
                close = i;
            }
            else if(s[i]=='/'){
                divi = i;
            }
        }
        int num = stoi(s.substr(1,plus-1))+stoi(s.substr(plus+1,close-plus-1));
        int den = stoi(s.substr(divi+1,s.length()-divi-1));
        int g = gc(num,den);
        num/=g;
        den/=g;
        li.push_back(make_pair(num*10000+den,z));
    }
    sort(li.begin(),li.end());
    for(int i = 0; i<n; i++){
        if(i!=0 && li[i].first==li[i-1].first){
            continue;
        }
        int j = i;
        while(j+1<n && li[i].first==li[j+1].first){
            j++;
        }
        int now = j-i+1;
        for(int k = i; k<=j; k++){
            ans[li[k].second] = now;
        }
    }
    cout << ans[0];
    for(int i = 1; i<n; i++){
        cout << " " << ans[i];
    }
    cout << endl;
    return 0;
}