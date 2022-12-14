/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author marX
 */

#include <iostream>
#include <fstream>

#include <bits/stdc++.h>

using namespace std;

class ACompetitiveProgrammer {
public:
    void solve(std::istream &in, std::ostream &out) {
        int t;
        in >> t;

        while (t--) {
            string s;
            in >> s;

            int sm = 0;
            int zero = 0;
            int even = 0;

            for (auto x : s) {
                sm += x - '0';
                zero += x == '0';
                even += (x - '0') % 2 == 0;
            }

            out << (sm % 3 == 0 && zero >= 1 && even >= 2 ? "red" : "cyan") << endl;
        }
    }
};


int main() {
    ACompetitiveProgrammer solver;
    std::istream &in(std::cin);
    std::ostream &out(std::cout);
    solver.solve(in, out);
    return 0;
}