def ask(p, q, r):
    print('?', p, q, r)
    answer = int(input())
    return answer


def find_answer(p, q, r, s):

    #print('find_answer', p, q, r, s)

    answer_pqr = ask(p, q, r)
    answer_qrs = ask(q, r, s)
    answer_rsp = ask(r, s, p)
    answer_spq = ask(s, p, q)

    MX = max(answer_pqr, answer_qrs, answer_rsp, answer_spq)

    if answer_pqr == MX and answer_spq == MX:
        return [p, q]

    if answer_pqr == MX and answer_rsp == MX:
        return [p, r]

    if answer_rsp == MX and answer_spq == MX:
        return [p, s]

    if answer_pqr == MX and answer_qrs == MX:
        return [q, r]

    if answer_qrs == MX and answer_spq == MX:
        return [q, s]

    return [r, s]


class Solver1634D:

    def __init__(self):
        self.n = int(input())

    def solve(self):
        answer = find_answer(1, 2, 3, 4)

        if self.n % 2 == 1:
            for i in range(1, 5):
                if answer[0] != i and answer[1] != i:
                    answer = find_answer(answer[0], answer[1], i, 5)
                    break

        for i in range(5 + self.n % 2, self.n+1, 2):
            answer = find_answer(answer[0], answer[1], i, i+1)

        print('!', answer[0], answer[1])


t = int(input())

while t:

    t -= 1

    cur = Solver1634D()

    cur.solve()