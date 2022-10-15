var
  Field: array [1..9, 1..9] of Char;
  s, str: string;
  i, j, x, y: LongInt;
  Filled: Boolean;

procedure SuperTrim(var s: string);
var
  minus: LongInt;
begin
  minus := 0;
  For i := 1 to Length(s) do
  begin
    If ord(s[i-minus]) < 33 then
    begin
      Delete(s, i-minus, 1);
      inc(minus);
    end;
  end;
end;

begin
  ReadLn(s);
  For i := 2 to 11 do
  begin
    ReadLn(str);
    s := s + str;
  end;

  SuperTrim(s);

  For i := 1 to 9 do
  begin
    For j := 1 to 9 do
    begin
      Field[i, j] := s[(i-1)*9 + j];
    end;
  end;

  Read(y, x);
  ReadLn;
  x := ((x - 1) mod 3)*3 + 1;
  y := ((y - 1) mod 3)*3 + 1;

  Filled:=True;
  For i := 0 to 2 do
  begin
    For j := 0 to 2 do
    begin
      If Field[y+i, x+j] = '.' then Filled := False;
    end;
  end;

  If Filled then
  begin
    For i := 1 to 9 do
    begin
      For j := 1 to 9 do
      begin
        If Field[i, j] = '.' then Field[i, j] := '!'
      end;
    end;
  end else
  begin
    For i := 0 to 2 do
    begin
      For j := 0 to 2 do
      begin
        If Field[y+i, x+j] = '.' then Field[y+i, x+j] := '!'
      end;
    end;
  end;

  For i := 1 to 9 do
  begin
    For j := 1 to 9 do
    begin
      Write(Field[i, j]);
      If (j = 3) or (j = 6) then Write(' ');
    end;
    If (i = 3) or (i = 6) then WriteLn('');
    WriteLn('');
  end;
end.