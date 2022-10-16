#include<bits/stdc++.h>
using namespace std;

long long int parent[26]{0};
long long int dp[26]{0};
long long int size1[26]{0};

long long int find_set(long long int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void make_set(long long int v) {
    parent[v] = v;
    size1[v] = 1;
}
 
void union_sets(long long int a,long long int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (size1[a] < size1[b])
            swap(a, b);
        parent[b] = a;
        size1[a] += size1[b];
    }
}

long long int val(char c){
    return int(c)-int('a');
}

void solve(){
    long long int n;cin>>n;
    set<char>s;
    for(long long int i=0;i<26;i++){
        parent[i]=-1;
    }
    string d;
    for(long long int i=0;i<n;i++){
        cin>>d;
        for(char c:d){
            if(s.find(c)==s.end()){
                make_set(val(c));
                union_sets(val(c),val(d[0]));
                s.insert(c);
            }else{
                union_sets(val(c),val(d[0]));
            }
        }
    }
    bool flag[26]{0};
    //cout<<flag[0]<<"\n";
    long long int ans =0 ;
    long long int h;
    for(long long int i=0;i<26;i++){
        if(parent[i]!= -1){
            h = find_set(i);
            if( flag[h] ){}
            else{
                //cout<<char(h+int('a'))<<"\n";
                ans++;
                flag[h]=true;
            }
        }
    }
    cout<<ans<<"\n";
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num = 1 ;
    //cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }
}