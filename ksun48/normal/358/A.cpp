#include <iostream>
using namespace std;
int compare(int a, int b, int c, int d){
    if(a>b) swap(a,b);
    if(c>d) swap(d,c);
    if(c<a && a < d && d < b) return 1;
    if(a<c && c < b && b < d) return 1;
    return 0;
}
int main() {
    int n;
    cin >> n;
    int a[n];
    if(n == 1){
        cout << "no" << endl;
        return 0;
    }
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 1; i < n; i++){
        for(int j = 1; j < n; j++){
            if(compare(a[i-1], a[i], a[j-1], a[j])){
                cout << "yes" << endl;
                return 0;
            }
        }
    }
            cout << "no" << endl;
        return 0;
}