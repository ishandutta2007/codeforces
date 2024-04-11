#include <bits/stdc++.h>
using namespace std;




int n;


vector<int> input;


int get_min_value()
    {
    int returned = 0;
    int delta = input[1] - input[0];
    for (size_t i = 2; i < n; i++)
        {
        int distance = -input[i] + input[0] + delta*i;
        if (distance < 0) distance = -distance;
        if (distance == 0) continue;
        if (distance == 1) returned++;
        else return -1;
        }

    return returned;
    }



int main()
{

    int tmp = -1;
    cin >> n;
                           //   765
    input.resize(n);       //   814
                           //   923
    for (size_t i = 0; i < n; i++)
        cin >> input[i];

    if (n < 3)
        {
        cout << 0;
        return 0;
        }

    int MAX = get_min_value();

    input[0]--;
    if ((tmp = get_min_value()) != -1 && (MAX > tmp + 1 || MAX == -1)) MAX = tmp + 1;
    //cout << tmp << endl;

    input[1]++;
    if ((tmp = get_min_value()) != -1 && (MAX > tmp + 2 || MAX == -1)) MAX = tmp + 2;

    input[0]++;
    if ((tmp = get_min_value()) != -1 && (MAX > tmp + 1 || MAX == -1)) MAX = tmp + 1;

    input[0]++;
    if ((tmp = get_min_value()) != -1 && (MAX > tmp + 2 || MAX == -1)) MAX = tmp + 2;

    input[1]--;
    if ((tmp = get_min_value()) != -1 && (MAX > tmp + 1 || MAX == -1)) MAX = tmp + 1;

    input[1]--;
    if ((tmp = get_min_value()) != -1 && (MAX > tmp + 2 || MAX == -1)) MAX = tmp + 2;

    input[0]--;
    if ((tmp = get_min_value()) != -1 && (MAX > tmp + 1 || MAX == -1)) MAX = tmp + 1;

    input[0]--;
    if ((tmp = get_min_value()) != -1 && (MAX > tmp + 2 || MAX == -1)) MAX = tmp + 2;





    cout << MAX;
}