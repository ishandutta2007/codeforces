var
    f, i, t, c, e, i1, i2: Int32;
    matrix: array [1..10] of string;
begin
    readLn(f, i, t);
    for i1 := 1 to f do ReadLn(matrix[i1]);
    c := 0;
    for i2 := 1 to i do
    begin
        e := 0;
        for i1 := 1 to f do if matrix[i1][i2] = 'Y' then e += 1;
        if e >= t then c += 1;
    end;
    WriteLn(c);
end.
//kitten