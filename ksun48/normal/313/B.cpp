#include <iostream>
#include <string>
#include <string.h>
using namespace std;
char sa[200000];
int l[200000];
int m[200000];
int ans[200000];
int main() {
    cin >> sa;
    int len = strlen(sa);
    ans[0] = 0;
    ans[1] = 0;
    for(int i = 2; i <= len; i++){
        ans[i] = ans[i-1];
        if(sa[i-1] == sa[i-2]){
            ans[i]++;
        }
        //cout << ans[i] << endl;
    }
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> l[i] >> m[i];
        cout << ans[m[i]]-ans[l[i]] << endl;
    }
    return 0;
}