var n, i: integer;
    T: array[1..90] of integer;
begin
    read(n);
    for i := 1 to n do read(T[i]);
    if T[1] > 15 then write(15)
    else
    begin
        i := 1;
        while ((T[i] + 15 >= T[i + 1]) and (i < n)) do i := i + 1;
        if T[i] < 75 then write(T[i] + 15) else write(90);
    end;
end.