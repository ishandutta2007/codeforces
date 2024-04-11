<?php
class INPUT_HELP{
    public function read_array(){
        $a[0] = '';
        $j = 0;
        $input = fgets(STDIN);
        for ($i = 0; $i < strlen($input); $i++){
            if (preg_replace("/[0-9A-z-._-]/",null,$input[$i]) == false) {
                $a[$j] = $a[$j].$input[$i];
            } else {
                if ($a[$j] != '') {
                    ++$j;
                    $a[$j] = '';
                }
            }
        }
        return $a;
    }
    public function read_one(){
        $array = $this->read_array();
        return $array[0];
    }
}
?>
<?php
    $input_connect = new INPUT_HELP();
    $n = $input_connect->read_one();
    $a = $input_connect->read_array();
    for ($i = 0; $i < $n; $i++) {
        $num[$i] = $i;
    }
    for ($i = $n; $i < 2 * $n; $i++){
        $a[$i] = $a[$i - $n];
        $num[$i] = $num[$i - $n];
    }
    $h = -1;
    for ($j = 1; $j < $n; $j++){
        if ($n % $j != 0 || $n / $j < 3) continue;
        ++$h;
        $div[$h] = $j;
    }
    for ($i = 0; $i < $n; $i++){
        if ($a[$i] == 0) continue;
        for ($j = 0; $j <= $h; $j++){
            $k = $i + $div[$j];
            while ($a[$k] == 1 && $num[$k] != $i) $k += $div[$j];
            if ($num[$k] == $i) {
                echo "YES";
                die(0);
            }
        } 
    }
    echo "NO";
?>