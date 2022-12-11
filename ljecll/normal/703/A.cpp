#include <iostream>

using namespace std;

int main()
{
    int n; cin >> n;
    int a[n], b[n];
    int ac=0;
    int bc=0;
    for (int i=0; i<n; i++){
        cin >> a[i] >> b[i];
        if (a[i]>b[i]){
            ac++;
        }
        if (a[i]<b[i]){
            bc++;
        }
    }
    if (ac > bc){
        cout << "Mishka";
    }
    if (ac == bc){
        cout << "Friendship is magic!^^";
    }
    if (ac < bc){
        cout << "Chris";
    }
    return 0;
}