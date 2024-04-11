uses
  Math;

var
  R, C, i, j: Int32;
  Field: array [0..501, 0..501] of Char;
  ans: Boolean;


begin
  For i := 1 to 501 do
  begin
    For j := 1 to 501 do
    begin
      Field[i, j] := '.';
    end;
  end;
  ans := True;

  ReadLn(R, C);
  For i := 1 to R do
  begin
    For j := 1 to C do
    begin
      Read(Field[i, j]);
    end;
    ReadLn;
  end;

  For i := 1 to R do
  begin
    For j := 1 to C do
    begin
      If Field[i, j] = 'W' then
      begin
        If Field[i, j+1] = '.' then Field[i, j+1] := 'D';
        If (Field[i, j+1] = 'S') then ans := False;

        If Field[i, j-1] = '.' then Field[i, j-1] := 'D';
        If (Field[i, j-1] = 'S') then ans := False;

        If Field[i+1, j] = '.' then Field[i+1, j] := 'D';
        If (Field[i+1, j] = 'S') then ans := False;

        If Field[i-1, j] = '.' then Field[i-1, j] := 'D';
        If (Field[i-1, j] = 'S') then ans := False;

      end;
    end;
  end;

  If not ans then WriteLn('No') else
    begin
      WriteLn('Yes');
      For i := 1 to R do
      begin
        For j := 1 to C do
        begin
          Write(Field[i, j]);
        end;
        WriteLn;
      end;
    end;
  ReadLn;
end.