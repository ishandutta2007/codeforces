try:
    while True:
        if input().startswith('Is it rated?'):
            print('NO', flush=True)
        else:
            print('YES', flush=True)
except EOFError:
    pass