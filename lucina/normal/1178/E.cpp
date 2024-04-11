#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
char s[maxn];
char x,y,z,w;
deque<char> d;
vector<char> st,ed;
int main(){
    scanf("%s",s+1);
    for(int i=1;s[i]!='\0';i++){
        d.push_back(s[i]);
    }
    while(d.size()>=4){
        x=d.front();d.pop_front();
        y=d.front();d.pop_front();
        z=d.back();d.pop_back();
        w=d.back();d.pop_back();
        if(x==z||x==w){
            st.push_back(x);
            ed.push_back(x);
            continue;
        }
        else{
            st.push_back(y);
            ed.push_back(y);
        }
    }
    if(d.size()){
        st.push_back(d.front());
    }
    reverse(ed.begin(),ed.end());
    for(auto i:st){
        printf("%c",i);
    }
    for(auto i:ed){
        printf("%c",i);
    }
}
/*
    Good Luck
        -Lucina
*/