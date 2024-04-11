#include <bits/stdc++.h>
using namespace std;


int n;
vector<int> data;

int get_chetnost ()
    {
    vector<bool> used (n+1, false);
    int chetnost = 0;
    for (int i = 1; i <= n; i++)
        {
        if (used[i]) continue;
        int j = i;
        while (!used[j])
            {
            chetnost++;
            used[j] = true;
            j = data[j];
            }
        chetnost--;
        chetnost = chetnost%2;
        }
    return chetnost;
    }





int main()
    {

    cin >> n;

    data.resize(n+1);

    for (int i = 1; i <= n; i++)
        {
        cin >> data[i];
        }

    //cout << get_chetnost();

    if ((n-get_chetnost())%2 == 1) cout << "Um_nik";
    else cout << "Petr";



    return 0;
    }