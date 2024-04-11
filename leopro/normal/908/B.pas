program Project1;

uses
  Classes;

var
  u, l, d, r, n, m, x, y, i, counter, Sx, Sy, Ex, Ey: LongInt;
  Filled: array [-1..50, -1..50] of Boolean;
  c: Char;
  a: array [-1..50, -1..50] of Char;
  Numbers: TStringList;
  s: string;
  str: array [0..50] of string;

begin
  Read(n, m);
  ReadLn;
  For u := -1 to n do
  begin
    Filled[u, -1] := True;
    Filled[u, m] := true;
  end;
  For u := -1 to m do
  begin
    Filled[-1, u] := True;
    Filled[n, u] := True;
  end;

  For u := 0 to n-1 do
  begin
    For l := 0 to m-1 do
    begin
      Read(c);
      If c = '.' then Filled[u, l] := False;
      If c = '#' then Filled[u, l] := True;
      If c = 'S' then
      begin
        Sx := l;
        Sy := u;
      end;
      If c = 'E' then
      begin
        Ex := l;
        Ey := u;
        Filled[u, l] := False;
      end;
    end;
    readln;
  end;
  ReadLn(s);

  counter := 0;
  Numbers := TStringList.Create;
  For u := 0 to 3 do
  begin
    For l := 0 to 2 do
    begin
      For d := 0 to 1 do
      begin
        For r := 0 to 0 do
        begin
          Numbers.Clear;
          Numbers.Insert(r, '0');
          Numbers.Insert(d, '1');
          Numbers.Insert(l, '2');
          Numbers.Insert(u, '3');
          x := Sx;
          y := Sy;
          For i := 1 to Length(s) do
          begin

            If s[i] = Numbers[0] then y := y - 1;
            If s[i] = Numbers[1] then x := x - 1;
            If s[i] = Numbers[2] then inc(y);
            If s[i] = Numbers[3] then inc(x);

            If Filled[y, x] then
            begin
              Break;
            end;
            If (x = Ex) and (y = Ey) then
            begin
              inc(counter);
              Break;
            end;
          end;

        end;
      end;
    end;
  end;
  WriteLn(counter);
end.