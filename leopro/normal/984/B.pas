var
  n, m, i, j: Int32;
  field: array [0..101, 0..101] of Char;
  ans: string;

begin
  ReadLn(n, m);
  For i := 0 to n+1 do 
  begin
    For j := 0 to m+1 do
    begin
      Field[i, j] := '0'
    end;
  end;
  For i := 1 to n do 
  begin
    For j := 1 to m do
    begin
      Read(field[i, j]);
      If Field[i, j] = '.' then Field[i, j] := '0';
      If Field[i, j] = '*' then Field[i, j] := '!';
    end;
    ReadLn;
  end;
  
  For i := 1 to n do
  begin
    For j := 1 to m do
    begin
      If Field[i, j] = '!' then 
      begin
        If Field[i-1, j-1] <> '!' then Field[i-1, j-1] := chr(ord(Field[i-1, j-1])-1);
        If Field[i, j-1] <> '!' then Field[i, j-1] := chr(ord(Field[i, j-1])-1);
        If Field[i+1, j-1] <> '!' then Field[i+1, j-1] := chr(ord(Field[i+1, j-1])-1);
        If Field[i-1, j] <> '!' then Field[i-1, j] := chr(ord(Field[i-1, j])-1);
        If Field[i+1, j] <> '!' then Field[i+1, j] := chr(ord(Field[i+1, j])-1);
        If Field[i-1, j+1] <> '!' then Field[i-1, j+1] := chr(ord(Field[i-1, j+1])-1);
        If Field[i, j+1] <> '!' then Field[i, j+1] := chr(ord(Field[i, j+1])-1);
        If Field[i+1, j+1] <> '!' then Field[i+1, j+1] := chr(ord(Field[i+1, j+1])-1);
      end;
    end;
  end;
  
  ans := 'YES';
  For i := 1 to n do
  begin
    For j := 1 to m do
    begin
      If (Field[i, j] <> '!') and (Field[i, j] <> '0') then 
      begin
        ans := 'NO'
      end;
    end;
  end;
  WriteLn(ans);
end.