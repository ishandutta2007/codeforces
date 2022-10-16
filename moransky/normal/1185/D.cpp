#include <cstdio>
#include <iostream>
#include <set>
#include <unordered_map>
#include <algorithm>
using namespace std;
typedef multiset<int>::iterator MIT;
const int N = 200005;
int n, a[N], b[N], tot, c[N];
bool flag = true;
set<int> s;
unordered_map<int, int> st, ik;
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", b + i), ik[b[i]] = i;
    }
    sort(b + 1, b + 1 + n);
    for(int i = 1; i < n; i++) {
        a[i] = b[i + 1] - b[i];
        s.insert(a[i]);
        st[a[i]]++;
    }
    for(MIT i = s.begin(); i != s.end(); i++){
        if(st[*i] >= n - 3) {
            //cout << *i << endl;
            bool flag = true;
            int ans = n; tot = 0;
            for(int j = 1; j < n; j++)
                if(j == 1 || b[j] - c[tot]   == *i) c[++tot] = b[j];
                else ans = j;
    
            if(b[n] - c[tot] == *i) c[++tot] = b[n];
            
            if(tot >= n - 1){
                printf("%d\n", ik[b[ans]]);
                return 0;
            }

            flag = true;
            ans = 1; tot = 0;
            for(int j = 2; j < n; j++)
                if(j == 2 || b[j] - c[tot]   == *i) c[++tot] = b[j];
                else ans = j;
    
            if(b[n] - c[tot] == *i) c[++tot] = b[n];
            
            if(tot >= n - 1){
                printf("%d\n", ik[b[ans]]);
                return 0;
            }

            flag = true;
            ans = 2; tot = 0;
            for(int j = 3; j < n; j++)
                if(j == 3 || b[j] - c[tot]   == *i) c[++tot] = b[j];
                else ans = j;
    
            if(b[n] - c[tot] == *i) c[++tot] = b[n];
            
            if(tot >= n - 1){
                printf("%d\n", ik[b[ans]]);
                return 0;
            }
        }
    }
    puts("-1");
    return 0;
}