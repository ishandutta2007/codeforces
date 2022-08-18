//
//  main.cpp
//  Contests
//
//  Created by Roman Rubanenko on 3/5/17.
//  Copyright  2017 Roman Rubanenko. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Student {
    int out, num;
    
    bool operator<(const Student& rhs) const {
        return out < rhs.out;
    }
    
};

constexpr int MAX_N = 128;

bool knows[MAX_N];


void hal() {
    cout << "-1\n";
    exit(0);
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<Student> students(n);
    for (int i = 0; i < n; i++) {
        cin >> students[i].out;
        students[i].num = i + 1;
    }
    sort(students.begin() + 1, students.end());
    reverse(students.begin() + 1, students.end());
    knows[1] = true;
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++) {
        auto& curStudent = students[i];
        if (!knows[curStudent.num]) {
            hal();
        }
        for (int j = i + 1; j < n && curStudent.out > 0; j++) {
            auto& otherStudent = students[j];
            if (!knows[otherStudent.num]) {
                curStudent.out--;
                knows[otherStudent.num] = true;
                ans.push_back({curStudent.num, otherStudent.num});
            }
        }
    }
    cout << ans.size() << '\n';
    for (const auto& p : ans) {
        cout << p.first << ' ' << p.second << '\n';
    }
    return 0;
}