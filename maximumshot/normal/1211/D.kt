import java.lang.Integer.min

const val MAX_RATING = 1_000_005

fun main() {
    val (n, a, b, k) = readLine()!!.split(" ").map { it.toInt() }
    val count = IntArray(MAX_RATING) { 0 }
    var ratings = readLine()!!.split(" ").map { it.toInt() }
    var teamsNumber = 0
    ratings.forEach { rating -> count[rating]++ }
    if (a > b) {
        for (rating in 1 until MAX_RATING) {
            val nextRating = rating * k
            if (nextRating >= MAX_RATING) {
                break
            }
            val addTeams = min(count[rating] / a, count[nextRating] / b)
            teamsNumber += addTeams
            count[nextRating] -= addTeams * b
        }
    } else {
        for (rating in MAX_RATING - 1 downTo 1) {
            if (rating % k != 0) {
                continue
            }
            val previousRating = rating / k
            val addTeams = min(count[previousRating] / a, count[rating] / b)
            teamsNumber += addTeams
            count[previousRating] -= addTeams * a
        }
    }
    println(teamsNumber)
}