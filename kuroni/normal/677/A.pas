var n, h, ans, i, temp: longint;
begin
    ans := 0;
    read(n,h);
    for i := 1 to n do
    begin
        read(temp);
        if temp > h then ans := ans + 2 else ans := ans + 1;
    end;
    write(ans);
end.