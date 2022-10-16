#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
    int h, w;
    cin >> w >> h;
    vector<vector<char> > base, mirr;
    base.resize(h);
    mirr.resize(w);
    for (int i = 0; i < h; i++)
    {
        base[i].resize(w);
        for (int j= 0; j < w; j++)
            cin >> base[i][j];
    }
    for (int i = 0; i < w; i++)
        mirr[i].resize(h);

    for (int i = 0; i < w; i++)
        for (int j = 0; j < h; j++)
            mirr[i][j] = base[j][i];

    for (int i = 0; i < 2 * w; i++)
    {
        for (int j = 0; j < 2 * h; j++)
            cout << mirr[i / 2][j / 2];
        cout << endl;
    }
    return 0;
}