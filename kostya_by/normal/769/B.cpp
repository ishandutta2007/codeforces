#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 101;

int n;
int outgoing_messages_limit[kMaxN];
int messages_sent[kMaxN];

pair<int, int> sending_order[kMaxN];
vector<pair<int, int>> output_messages;

void ReadInput() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &outgoing_messages_limit[i]);
  }
}

void BuildSendingOrder() {
  for (int i = 0; i < n; ++i) {
    sending_order[i] = {-outgoing_messages_limit[i], i};
  }

  // Skipping the first guy as he knows the news from the beginning
  sort(sending_order + 1, sending_order + n);
}

bool SendMessagesGreedly() {
  int sender_ptr = 0;
  const auto sender_id = [&]() { return sending_order[sender_ptr].second; };

  for (int i = 1; i < n; ++i) {
    while (messages_sent[sender_id()] >= outgoing_messages_limit[sender_id()] && sender_ptr < i) {
      ++sender_ptr;
    }

    if (i == sender_ptr) {
      return false;
    }

    output_messages.push_back({sender_id(), sending_order[i].second});
    ++messages_sent[sender_id()];
  }

  return true;
}

void WriteOutput(bool is_successful) {
  if (is_successful) {
    printf("%lu\n", output_messages.size());
    for (const auto& message : output_messages) {
      printf("%d %d\n", message.first + 1, message.second + 1);
    }
  } else {
    printf("-1\n");
  }
}

void Solve() {
  ReadInput();
  BuildSendingOrder();
  bool is_successful = SendMessagesGreedly();
  WriteOutput(is_successful);
}

int main() {
  Solve();

  return 0;
}