def ask(a, b):
    print("?", a, b, flush=True)
    return int(input()) <= 0


def solve(M):
    a, b = 0, 0
    less = ask(0, 0)

    for i in range(M - 1, -1, -1):
        bit = 1 << i
        
        if less:
            if not ask(a | bit, b | bit):
                b |= bit
                less = ask(a, b)
            elif ask(a | bit, b):
                a |= bit
                b |= bit
        else:
            if ask(a | bit, b | bit):
                a |= bit
                less = ask(a, b)
            elif ask(a | bit, b):
                a |= bit
                b |= bit

    print("!", a, b, flush=True)

if __name__ == '__main__':
    solve(30)