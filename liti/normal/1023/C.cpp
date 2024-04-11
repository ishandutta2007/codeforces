//In the name of Allah
#include <bits/stdc++.h>
using namespace std; 

typedef long long ll; 

typedef pair<int,int> pii; 

const int maxN = 1000 * 100 * 2 + 100;
pii a[maxN];
int mark[maxN];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s; 

    stack<int> st; 
    int en = 0;
    for(int i = 0; i < n; i++) 
        if( s[i] == '(' ) 
            st.push(i);
        else { 
            int v = st.top(); 
            st.pop();
            a[en++] = pii( i - v , v ); 
        }

    sort( a, a + en ); 

    for(int i = 0; i < (n-k)/2 ; i++) {
        mark[ a[i].second ] = 1; 
        mark[ a[i].first + a[i].second ] = 1; 
    }

    for(int i = 0 ; i < n; i++)
        if( !mark[i] ) 
            cout << s[i];
    cout << endl;

    return 0;
}